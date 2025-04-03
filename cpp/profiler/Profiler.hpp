#pragma once

#include <ctime>
#include <string>

enum ProfileFilter {
    PROFILE_WALL,
    PROFILE_CPU,
    PROFILE_ALL,
};

enum DumpFilter {
    DUMP_SECONDS,
    DUMP_NANO,
    DUMP_ALL,
};

class Profiler {
  public:
    virtual void start();
    virtual void end();

    void dump();
    void wallDump();
    void cpuDump();

    std::string getProfilerFilter() const;
    inline void setProfilerFilter(const ProfileFilter &filter) { this->m_profilerFilter = filter; }

    inline void setDumpFilter(const DumpFilter &filter) { this->m_dumpFilter = filter; }

    Profiler(const ProfileFilter &filter = PROFILE_ALL, const DumpFilter &dumpFilter = DUMP_SECONDS)
        : m_profilerFilter(filter), m_dumpFilter(dumpFilter) {}

  private:
    ProfileFilter m_profilerFilter{PROFILE_ALL};
    DumpFilter m_dumpFilter{DUMP_SECONDS};

    std::timespec m_wallBegin{};
    std::timespec m_wallEnd{};
    std::timespec m_cpuBegin{};
    std::timespec m_cpuEnd{};

    double m_walls{};
    double m_walln{};
    double m_cpus{};
    double m_cpun{};
};
