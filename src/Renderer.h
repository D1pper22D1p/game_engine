#pragma once
#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <DirectXMath.h>
#include <wrl/client.h>
#include <vector>
#include "Mesh.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;

class Renderer{
public:
    Renderer();
    ~Renderer();

    bool Initialize(HWND hwnd, int width, int height);
    void BeginFrame();
    void Render();
    void EndFrame();
    void Shutdown();

private:
    bool InitializeDirectX(HWND hwnd, int width, int height);
    bool CreateCommandObjects();
    bool CreateSwapChain(HWND hwnd);
    bool CreateRenderTargets();
    bool CreateDepthBuffer();
    bool CreateRootSignature();
    bool CreatePipelineState();
    void CreateMeshes();
    void UpdateViewport();

    ComPtr<ID3D12Device> m_device;
    ComPtr<IDXGIFactory4> m_factory;
    ComPtr<IDXGISwapChain3> m_swapChain;
    ComPtr<ID3D12CommandQueue> m_commandQueue;
    ComPtr<ID3D12CommandAllocator> m_commandAllocator;
    ComPtr<ID3D12GraphicsCommandList> m_commandList;

    ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
    ComPtr<ID3D12DescriptorHeap> m_dsvHeap;
    ComPtr<ID3D12Resource> m_renderTargets[2];
    ComPtr<ID3D12Resource> m_depthStencilBuffer;

    ComPtr<ID3D12RootSignature> m_rootSignature;
    ComPtr<ID3D12PipelineState> m_pipelineState;
    ComPtr<ID3D12Fence> m_fence;

    std::vector<Mesh> m_meshes;

    int m_width;
    int m_height;
    int m_currentBackBufferIndex;
    UINT64 m_fenceValue;
    HANDLE m_fenceEvent;

    D3D12_VIEWPORT m_viewport;
    D3D12_RECT m_scissorRect;
};