/** \file .h
*	\brief
*/

#pragma once

#include "system.h"
#include "assetManager.h"
#include "rendering/buffers.h"
#include "rendering/vertexArray.h"
#include "rendering/texture.h"
#include "rendering/shader.h"
#include "rendering/material.h"
#include "rendering/uniformBuffers.h"


namespace Engine {

	/**	\class
	*	\brief
	*/

	class ResourceManager : public System
	{
	private:
		static AssetManager<IndexBuffer> m_indexBuffers;
		static AssetManager<Shader> m_shaders;
		static AssetManager<Texture> m_textures;
		static AssetManager<VertexArray> m_VAOs;
		static AssetManager<VertexBuffer> m_VBOs;
		static AssetManager<UniformBuffer> m_UBOs;
		static AssetManager<Material> m_materials;

	public:
		void start(SystemSignal init = SystemSignal::None, ...) override {};	//!< overridden start/init function
		void stop(SystemSignal close = SystemSignal::None, ...) override {};	//!< overridden stop/close function

		static std::shared_ptr<IndexBuffer> addIndexBuffer(const std::string& name, unsigned int* indices, unsigned int count);
		static std::shared_ptr<Shader>  addShader(const std::string& filepath);
		static std::shared_ptr<Texture>  addTexture(const std::string& filepath);
		static std::shared_ptr<VertexArray>  addVAO(const std::string& name);
		static std::shared_ptr<VertexBuffer>  addVBO(const std::string& name, float* vertices, unsigned int size, VertexBufferLayout& layout);
		static std::shared_ptr<UniformBuffer>  addUBO(const std::string& name, unsigned int size, UniformBufferLayout& layout);
		static std::shared_ptr<Material>  addMaterial(const std::string& name, const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& VAO);
	};

}