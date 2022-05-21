#pragma once
#include <glfw/glfw3.h>

#include "ShaderProgram.h"

#include "Device.h"
#include "DeviceContext.h"

class Scene
{
public:
	~Scene();

	void InitResource();
	void InitPipeline();
	void InitGraphics();
	void DrawSence();
	std::vector<Vertex> GetVertices();

	Device* device;
	DeviceContext* deviceiceContext;
	ShaderProgram shaderprogram;
	VertexBuffer* vertexBuffer;
	InputLayout* inputLayout;

private:
};

Scene::~Scene()
{
    delete device;
    delete deviceiceContext;
    delete vertexBuffer;
    delete inputLayout;
}

void Scene::InitResource() {
    device = new Device();
    deviceiceContext = new DeviceContext();

    vertexBuffer = new VertexBuffer();
    inputLayout = new InputLayout();

    InitGraphics();
    InitPipeline();
    DrawSence();
}

void Scene::DrawSence() {
    UINT stride = sizeof(SampleVertex);
    UINT offset = 0;
    deviceiceContext->SetVertexBuffer(0, 1, vertexBuffer, &stride, &offset);

    deviceiceContext->Draw(3, 0);
}


void Scene::InitPipeline() {
    INPUT_ELEMENT_DESC ied[] = {
        {"POSITION", sizeof(float) * 4},
        {"TEXCOORD", sizeof(float) * 2},
        {"NORMAL", sizeof(float) * 3},
    };
    device->CreateInputLayout(ied, ARRAYSIZE(ied), &inputLayout);
    deviceiceContext->SetInputLayout(inputLayout);
}

void Scene::InitGraphics() {
    SampleVertex vertices[] = {
        // 顶点坐标         纹理坐标     法向量
        {-0.5f, -0.5f, -0.5f,  1.0f, 0, 0, 0, 0, -1,},
        {0.5f, -0.5f, -0.5f,  1.0f, 0, 1, 0, 0, -1, },
        {0.5f,  0.5f, -0.5f,  1.0f, 1, 1, 0, 0, -1, },
        {0.5f,  0.5f, -0.5f,  1.0f, 1, 1, 0, 0, -1, },
        {-0.5f,  0.5f, -0.5f, 1.0f, 1, 0, 0, 0, -1, },
        {-0.5f, -0.5f, -0.5f, 1.0f, 0, 0, 0, 0, -1, },

        {-0.5f, -0.5f,  0.5f, 1.0f, 0, 0, 0, 0, 1, },
        {0.5f, -0.5f,  0.5f,  1.0f, 0, 1, 0, 0, 1, },
        {0.5f,  0.5f,  0.5f,  1.0f, 1, 1, 0, 0, 1, },
        {0.5f,  0.5f,  0.5f,  1.0f, 1, 1, 0, 0, 1, },
        {-0.5f,  0.5f,  0.5f, 1.0f, 1, 0, 0, 0, 1, },
        {-0.5f, -0.5f,  0.5f, 1.0f, 0, 0, 0, 0, 1, },

        {-0.5f,  0.5f,  0.5f,  1.0f, 0, 0, -1, 0, 0, },
        {-0.5f,  0.5f, -0.5f,  1.0f, 0, 1, -1, 0, 0, },
        {-0.5f, -0.5f, -0.5f,  1.0f, 1, 1, -1, 0, 0, },
        {-0.5f, -0.5f, -0.5f,  1.0f, 1, 1, -1, 0, 0, },
        {-0.5f, -0.5f,  0.5f,  1.0f, 1, 0, -1, 0, 0, },
        {-0.5f,  0.5f,  0.5f,  1.0f, 0, 0, -1, 0, 0, },

        {0.5f,  0.5f,  0.5f,  1.0f, 0, 0, 1, 0, 0, },
        {0.5f,  0.5f, -0.5f,  1.0f, 0, 1, 1, 0, 0, },
        {0.5f, -0.5f, -0.5f,  1.0f, 1, 1, 1, 0, 0, },
        {0.5f, -0.5f, -0.5f,  1.0f, 1, 1, 1, 0, 0, },
        {0.5f, -0.5f,  0.5f,  1.0f, 1, 0, 1, 0, 0, },
        {0.5f,  0.5f,  0.5f,  1.0f, 0, 0, 1, 0, 0, },

        {-0.5f, -0.5f, -0.5f, 1.0f, 0, 0, 0, -1, 0, },
        {0.5f, -0.5f, -0.5f,  1.0f, 0, 1, 0, -1, 0, },
        {0.5f, -0.5f,  0.5f,  1.0f, 1, 1, 0, -1, 0, },
        {0.5f, -0.5f,  0.5f,  1.0f, 1, 1, 0, -1, 0, },
        {-0.5f, -0.5f,  0.5f, 1.0f, 1, 0, 0, -1, 0, },
        {-0.5f, -0.5f, -0.5f, 1.0f, 0, 0, 0, -1, 0, },

        {-0.5f,  0.5f, -0.5f, 1.0f, 0, 0, 0, 1, 0, },
        {0.5f,  0.5f, -0.5f,  1.0f, 0, 1, 0, 1, 0, },
        {0.5f,  0.5f,  0.5f,  1.0f, 1, 1, 0, 1, 0, },
        {0.5f,  0.5f,  0.5f,  1.0f, 1, 1, 0, 1, 0, },
        {-0.5f,  0.5f,  0.5f, 1.0f, 1, 0, 0, 1, 0, },
        {-0.5f,  0.5f, -0.5f, 1.0f, 0, 0, 0, 1, 0, },
    };

    BUFFER_DESC bd = { 0 };
    bd.ByteWidth = sizeof(vertices);

    SUBRESOURCE_DATA srd = { (float*)vertices,0,0 };

    device->CreateBuffer(&bd, &srd, &vertexBuffer);
}

std::vector<Vertex> Scene::GetVertices() {
    return deviceiceContext->GetVertices();
}