/*******************************************************************************
 * CGoGN: Combinatorial and Geometric modeling with Generic N-dimensional Maps  *
 * Copyright (C), IGG Group, ICube, University of Strasbourg, France            *
 *                                                                              *
 * This library is free software; you can redistribute it and/or modify it      *
 * under the terms of the GNU Lesser General Public License as published by the *
 * Free Software Foundation; either version 2.1 of the License, or (at your     *
 * option) any later version.                                                   *
 *                                                                              *
 * This library is distributed in the hope that it will be useful, but WITHOUT  *
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License  *
 * for more details.                                                            *
 *                                                                              *
 * You should have received a copy of the GNU Lesser General Public License     *
 * along with this library; if not, write to the Free Software Foundation,      *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.           *
 *                                                                              *
 * Web site: http://cgogn.unistra.fr/                                           *
 * Contact information: cgogn@unistra.fr                                        *
 *                                                                              *
 *******************************************************************************/

#ifndef CGOGN_RENDERING_SHADERS_PHONG_SCALAR_PER_VERTEX_H_
#define CGOGN_RENDERING_SHADERS_PHONG_SCALAR_PER_VERTEX_H_

#include <cgogn/rendering/cgogn_rendering_export.h>
#include <cgogn/rendering/shader_program.h>
#include <cgogn/rendering/shaders/shader_function_color_maps.h>

namespace cgogn
{

namespace rendering
{

DECLARE_SHADER_CLASS(PhongScalarPerVertex, false, CGOGN_STR(PhongScalarPerVertex))

class CGOGN_RENDERING_EXPORT ShaderParamPhongScalarPerVertex : public ShaderParam
{
	void set_uniforms() override;

public:
	GLColor ambiant_color_;
	GLVec3 light_position_;
	bool double_side_;
	bool show_iso_lines_;
	int nb_iso_lines_;
	GLColor specular_color_;
	float32 specular_coef_;
	shader_function::ColorMap::Uniforms color_map_;

	using ShaderType = ShaderPhongScalarPerVertex;

	ShaderParamPhongScalarPerVertex(ShaderType* sh)
		: ShaderParam(sh), ambiant_color_(0.05f, 0.05f, 0.05f, 1), light_position_(10, 100, 1000), double_side_(true),
		  show_iso_lines_(false), nb_iso_lines_(10), specular_color_(1, 1, 1, 1), specular_coef_(250)
	{
	}

	inline ~ShaderParamPhongScalarPerVertex() override
	{
	}
};

} // namespace rendering

} // namespace cgogn

#endif // CGOGN_RENDERING_SHADERS_PHONG_SCALAR_PER_VERTEX_H_
