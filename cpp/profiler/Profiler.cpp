#include "Profiler.hpp"

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

std::string filterToString(const ProfileFilter &filter) {
    switch (filter) {
    case PROFILE_WALL:
        return "Wall";
    case PROFILE_CPU:
        return "CPU";
    case PROFILE_ALL:
        return "Wall + CPU";
    }
    return "";
}

void getTime(ProfileFilter &filter, std::timespec &wallTime, std::timespec &cpuTime) {
    switch (filter) {
    case PROFILE_WALL: {
        clock_gettime(CLOCK_REALTIME, &wallTime);
        return;
    }
    case PROFILE_CPU: {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpuTime);
        return;
    }
    case PROFILE_ALL: {
        clock_gettime(CLOCK_REALTIME, &wallTime);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpuTime);
        return;
    }
    }
}

void dumpFiltered(DumpFilter &filter, double &sec, double &nano, std::stringstream &out) {
    switch (filter) {
    case DUMP_SECONDS: {
        out << sec << "s";
        break;
    }
    case DUMP_NANO: {
        out << nano << "ns (1x10^-9 s)";
        break;
    }
    case DUMP_ALL: {
        out << sec << "s -> ";
        out << nano << "ns (1x10^-9 s)";
        break;
    }
    }
    out << "\n";
}

void Profiler::start() { getTime(this->m_profilerFilter, this->m_wallBegin, this->m_cpuBegin); }

void Profiler::end() { getTime(this->m_profilerFilter, this->m_wallEnd, this->m_cpuEnd); }

void Profiler::dump() {
    this->m_walls = this->m_wallEnd.tv_sec - this->m_wallBegin.tv_sec;
    this->m_walln = this->m_wallEnd.tv_nsec - this->m_wallBegin.tv_nsec;

    this->m_cpus = this->m_cpuEnd.tv_sec - this->m_cpuBegin.tv_sec;
    this->m_cpun = this->m_cpuEnd.tv_nsec - this->m_cpuBegin.tv_nsec;

    switch (this->m_profilerFilter) {
    case PROFILE_WALL: {
        this->wallDump();
        return;
    }
    case PROFILE_CPU: {
        this->cpuDump();
        return;
    }
    case PROFILE_ALL: {
        this->wallDump();
        this->cpuDump();
        return;
    }
    }
}

void Profiler::wallDump() {
    std::stringstream out{};
    out << "Wall Time: ";
    dumpFiltered(this->m_dumpFilter, this->m_walls, this->m_walln, out);
    std::cout << out.str();
}

void Profiler::cpuDump() {
    std::stringstream out{};
    out << "CPU Time: ";
    dumpFiltered(this->m_dumpFilter, this->m_cpus, this->m_cpun, out);
    std::cout << out.str();
}

std::string Profiler::getProfilerFilter() const { return filterToString(this->m_profilerFilter); }
