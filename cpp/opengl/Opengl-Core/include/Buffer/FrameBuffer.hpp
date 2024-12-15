#pragma once

#include "Buffer.hpp"

#include "../Core/Structs.hpp"
#include "RenderBuffer.hpp"

namespace ogl {
class FrameBuffer : public Buffer {
  public:
    virtual void onAttach() override;
    virtual void onDetach() override;

    virtual void bind() const override;
    virtual void unbind() const override;

    FrameBuffer() = delete;
    FrameBuffer(const FBConfig &config) : m_config(config) {}
    ~FrameBuffer() override;

  private:
    FBConfig m_config{};
    RenderBuffer m_rbo;
};
} // namespace ogl
