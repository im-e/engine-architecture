/** \file .h
*	\brief
*/

#pragma once
#include "systems/logger.h"

/**	\class
	*	\brief
	*/
enum class ShaderDataType
{
	None = 0, Int, Int2, Int3, Int4, Float, Float2, Float3, Float4, Mat3, Mat4, Bool, Sampler2D
};

static unsigned int ShaderDataTypeSize(ShaderDataType type)
{
	switch (type)
	{
	case ShaderDataType::Float:    return 4;
	case ShaderDataType::Float2:   return 4 * 2;
	case ShaderDataType::Float3:   return 4 * 3;
	case ShaderDataType::Float4:   return 4 * 4;
	case ShaderDataType::Mat3:     return 4 * 3 * 3;
	case ShaderDataType::Mat4:     return 4 * 4 * 4;
	case ShaderDataType::Int:      return 4;
	case ShaderDataType::Int2:     return 4 * 2;
	case ShaderDataType::Int3:     return 4 * 3;
	case ShaderDataType::Int4:     return 4 * 4;
	case ShaderDataType::Bool:     return 1;
	}

	LOG_ASSERT(false, "Unknown ShaderDataType Size!");
	return 0;
}

static unsigned int ShaderDataTypeComponentCount(ShaderDataType type)
{
	switch (type)
	{
	case ShaderDataType::Int:	return 1;
	case ShaderDataType::Int2:	return 2;
	case ShaderDataType::Int3:	return 3;
	case ShaderDataType::Int4:	return 4;
	case ShaderDataType::Float:	return 1;
	case ShaderDataType::Float2:	return 2;
	case ShaderDataType::Float3:	return 3;
	case ShaderDataType::Float4:	return 4;
	case ShaderDataType::Mat3:	return 3 * 3;
	case ShaderDataType::Mat4:	return 4 * 4;
	case ShaderDataType::Bool:	return 1;
	case ShaderDataType::Sampler2D:	return 1;
	}
	LOG_ASSERT(false, "Unknown ShaderDataType Component Count!");
	return 0;
}

static ShaderDataType GLSLStrToSDT(const std::string& glslSrc)
{
	ShaderDataType result = ShaderDataType::None;
	if (glslSrc == "bool") result = ShaderDataType::Bool;
	if (glslSrc == "int") result = ShaderDataType::Int;
	if (glslSrc == "ivec2") result = ShaderDataType::Int2;
	if (glslSrc == "ivec3") result = ShaderDataType::Int3;
	if (glslSrc == "ivec4") result = ShaderDataType::Int4;
	if (glslSrc == "float") result = ShaderDataType::Float;
	if (glslSrc == "vec2") result = ShaderDataType::Float2;
	if (glslSrc == "vec3") result = ShaderDataType::Float3;
	if (glslSrc == "vec4") result = ShaderDataType::Float4;
	if (glslSrc == "mat3") result = ShaderDataType::Mat3;
	if (glslSrc == "mat4") result = ShaderDataType::Mat4;
	if (glslSrc == "sampler2D") result = ShaderDataType::Sampler2D;
	return result;
}

