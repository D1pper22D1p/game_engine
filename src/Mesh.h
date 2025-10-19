#pragma once
#include <d3d12.h>
#include <DirectXMath.h>
#include <wrl/client.h>
#include <vector>

using Microsoft::WRL::ComPtr;
using namespace DirectX;

struct Vertex {
    XMFLOAT3 position;
    XMFLOAT4 color;
};

struct Mesh {
    std::vector<Vertex> vertices;
    std::vector<UINT> indices;
    
    ComPtr<ID3D12Resource> vertexBuffer;
    ComPtr<ID3D12Resource> indexBuffer;
    
    D3D12_VERTEX_BUFFER_VIEW vertexBufferView = {};
    D3D12_INDEX_BUFFER_VIEW indexBufferView = {};
    
    UINT indexCount = 0;
    XMFLOAT3 position = { 0, 0, 0 };
    XMFLOAT3 rotation = { 0, 0, 0 };
    XMFLOAT3 scale = { 1, 1, 1 };
    
    static Mesh CreateCube(float size) {
        Mesh mesh;
        float half = size / 2.0f;
        
        mesh.vertices = {
            { { -half, -half,  half }, { 1, 0, 0, 1 } },
            { {  half, -half,  half }, { 1, 0, 0, 1 } },
            { {  half,  half,  half }, { 1, 0, 0, 1 } },
            { { -half,  half,  half }, { 1, 0, 0, 1 } },
            
            { { -half, -half, -half }, { 0, 1, 0, 1 } },
            { { -half,  half, -half }, { 0, 1, 0, 1 } },
            { {  half,  half, -half }, { 0, 1, 0, 1 } },
            { {  half, -half, -half }, { 0, 1, 0, 1 } },
            
            { { -half,  half, -half }, { 0, 0, 1, 1 } },
            { { -half,  half,  half }, { 0, 0, 1, 1 } },
            { {  half,  half,  half }, { 0, 0, 1, 1 } },
            { {  half,  half, -half }, { 0, 0, 1, 1 } },
            
            { { -half, -half, -half }, { 1, 1, 0, 1 } },
            { {  half, -half, -half }, { 1, 1, 0, 1 } },
            { {  half, -half,  half }, { 1, 1, 0, 1 } },
            { { -half, -half,  half }, { 1, 1, 0, 1 } },
            
            { {  half, -half, -half }, { 0, 1, 1, 1 } },
            { {  half,  half, -half }, { 0, 1, 1, 1 } },
            { {  half,  half,  half }, { 0, 1, 1, 1 } },
            { {  half, -half,  half }, { 0, 1, 1, 1 } },
            
            { { -half, -half, -half }, { 1, 0, 1, 1 } },
            { { -half, -half,  half }, { 1, 0, 1, 1 } },
            { { -half,  half,  half }, { 1, 0, 1, 1 } },
            { { -half,  half, -half }, { 1, 0, 1, 1 } },
        };
        
        mesh.indices = {
            0, 1, 2, 0, 2, 3,
            4, 6, 5, 4, 7, 6,
            8, 9, 10, 8, 10, 11,
            12, 14, 13, 12, 15, 14,
            16, 17, 18, 16, 18, 19,
            20, 22, 21, 20, 23, 22
        };
        
        mesh.indexCount = static_cast<UINT>(mesh.indices.size());
        return mesh;
    }
    
    static Mesh CreatePyramid(float size) {
        Mesh mesh;
        float half = size / 2.0f;
        
        mesh.vertices = {
            { {  0,  half,  0 }, { 1, 1, 0, 1 } },
            { { -half, -half,  half }, { 1, 0, 0, 1 } },
            { {  half, -half,  half }, { 1, 0, 0, 1 } },
            { {  half, -half, -half }, { 0, 1, 0, 1 } },
            { { -half, -half, -half }, { 0, 1, 0, 1 } },
        };
        
        mesh.indices = {
            0, 2, 1,
            0, 3, 2,
            0, 4, 3,
            0, 1, 4,
            1, 2, 3,
            1, 3, 4
        };
        
        mesh.indexCount = static_cast<UINT>(mesh.indices.size());
        return mesh;
    }
};