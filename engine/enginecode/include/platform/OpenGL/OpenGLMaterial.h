/** \file .h
*	\brief
*/

#pragma once
#include <memory>
#include <map>
#include <variant>
#include "rendering/material.h"

namespace Engine {

	/**	\class
	*	\brief
	*/
	class OpenGLMaterial : public Material
	{
	public:

		OpenGLMaterial(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& VAO); //!< Initialise the material
		OpenGLMaterial(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexBuffer>& VBO); //!< Initialise the material

		void setShader(const std::shared_ptr<Shader>& shader) override; //!< Set the shader
		void setGeometry(const std::variant<std::shared_ptr<VertexArray>, std::shared_ptr<VertexBuffer>>& geometry) override; //!<)
		void setDataBlock(const std::map<std::string, void *>& data) override; //!< Set a block of data as the per draw data
		void setDataElement(const std::string& dataName, void * data) override; //!< set a single uniform
		//void setVertexData(float * vertices, unsigned int size, unsigned int offset) override; //!< Set the geometry directly
		
		inline std::shared_ptr<Shader> getShader() override { return m_shader; }; //!< Get the shader
		inline std::variant<std::shared_ptr<VertexArray>, std::shared_ptr<VertexBuffer>> getGeometry() override
		{ return std::variant<std::shared_ptr<VertexArray>, std::shared_ptr<VertexBuffer>>(m_geometry); }; //!< Get the geometry
		inline std::map<std::string, void *> getData() override { return m_data; }; //!< Get the per draw data

	private:

		std::shared_ptr<Shader> m_shader; //!< The shader
		std::shared_ptr<VertexArray> m_geometry; //!< The geometry
		std::map<std::string, void*> m_data; //!< The data

	};
}