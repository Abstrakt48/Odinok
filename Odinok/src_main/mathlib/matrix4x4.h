#ifndef __MATRIX4X4__
#define __MATRIX4X4__

#include <memory>

//
// Mat4x4
//
class Mat4x4
{
public:
	Mat4x4()
	{
		SetIdentity();
	}

	void SetIdentity()
	{
		memSet(m_mat, 0, sizeof(m_mat));
		m_mat[0][0] = 1;
		m_mat[1][1] = 1;
		m_mat[2][2] = 1;
		m_mat[3][3] = 1;
	}

	void SetTranslation(const  Vector3D& translation)
	{
		m_mat[3][0] = translation.x;
		m_mat[3][1] = translation.y;
		m_mat[3][2] = translation.z;
	}

	void SetScale(const  Vector3D& scale)
	{
		m_mat[0][0] = (float)scale.x;
		m_mat[1][1] = (float)scale.y;
		m_mat[2][2] = (float)scale.z;
	}

	void SetRotationX(float x)
	{
		m_mat[1][1] = (float)cos(x);
		m_mat[1][2] = (float)sin(x);
		m_mat[2][1] = (float)-sin(x);
		m_mat[2][2] = (float)cos(x);
	}

	void SetRotationY(float y)
	{
		m_mat[0][0] = (float)cos(y);
		m_mat[0][2] = (float)-sin(y);
		m_mat[2][0] = (float)sin(y);
		m_mat[2][2] = (float)cos(y);
	}

	void SetRotationZ(float z)
	{
		m_mat[0][0] = (float)cos(z);
		m_mat[0][1] = (float)sin(z);
		m_mat[1][0] = (float)-sin(z);
		m_mat[1][1] = (float)cos(z);
	}

	float GetDeterminant()
	{
		Vector4D minor, v1, v2, v3;
		float det = 0.0f;

		v1 = Vector4D(this->m_mat[0][0], this->m_mat[1][0], this->m_mat[2][0], this->m_mat[3][0]);
		v2 = Vector4D(this->m_mat[0][1], this->m_mat[1][1], this->m_mat[2][1], this->m_mat[3][1]);
		v3 = Vector4D(this->m_mat[0][2], this->m_mat[1][2], this->m_mat[2][2], this->m_mat[3][2]);


		minor.cross(v1, v2, v3);
		det = -(this->m_mat[0][3] * minor.x + this->m_mat[1][3] * minor.y + this->m_mat[2][3] * minor.z +
			this->m_mat[3][3] * minor.w);
		return det;
	}

	void Inverse()
	{
		int a = 0, i = 0, j = 0;
		Mat4x4 out = {};
		Vector4D v = {}, vec[3] = {};
		float det = 0.0f;

		det = this->GetDeterminant();
		if (!det) return;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (j != i)
				{
					a = j;
					if (j > i) a = a - 1;
					vec[a].x = (this->m_mat[j][0]);
					vec[a].y = (this->m_mat[j][1]);
					vec[a].z = (this->m_mat[j][2]);
					vec[a].w = (this->m_mat[j][3]);
				}
			}
			v.cross(vec[0], vec[1], vec[2]);

			out.m_mat[0][i] = (float)pow(-1.0f, i) * v.x / det;
			out.m_mat[1][i] = (float)pow(-1.0f, i) * v.y / det;
			out.m_mat[2][i] = (float)pow(-1.0f, i) * v.z / det;
			out.m_mat[3][i] = (float)pow(-1.0f, i) * v.w / det;
		}

		this->SetMatrix(out);
	}


	void operator *=(const  Mat4x4& m_matrix)
	{
		Mat4x4 out;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				out.m_mat[i][j] =
					m_mat[i][0] * m_matrix.m_mat[0][j] + m_mat[i][1] * m_matrix.m_mat[1][j] +
					m_mat[i][2] * m_matrix.m_mat[2][j] + m_mat[i][3] * m_matrix.m_mat[3][j];
			}
		}
		SetMatrix(out);
	}

	void SetMatrix(const  Mat4x4& m_matrix)
	{
		::memcpy(m_mat, m_matrix.m_mat, sizeof(m_mat));
	}

	Vector3D GetRightwardDirection()
	{
		return Vector3D(m_mat[0][0], m_mat[0][1], m_mat[0][2]);
	}
	Vector3D GetUpDirection()
	{
		return Vector3D(m_mat[1][0], m_mat[1][1], m_mat[1][2]);
	}
	Vector3D GetForwardDirection()
	{
		return Vector3D(m_mat[2][0], m_mat[2][1], m_mat[2][2]);
	}

	Vector3D GetTranslation()
	{
		return Vector3D(m_mat[3][0], m_mat[3][1], m_mat[3][2]);
	}

	void SetPerspectiveFovLH(float fov, float aspect, float znear, float zfar)
	{
		float yscale = 1.0f / (float)tan(fov / 2.0f);
		float xscale = yscale / aspect;
		m_mat[0][0] = xscale;
		m_mat[1][1] = yscale;
		m_mat[2][2] = zfar / (zfar - znear);
		m_mat[2][3] = 1.0f;
		m_mat[3][2] = (-znear * zfar) / (zfar - znear);
		m_mat[3][3] = 0.0f;

	}


	void SetOrthoLH(float width, float height, float near_plane, float far_plane)
	{
		SetIdentity();
		m_mat[0][0] = 2.0f / width;
		m_mat[1][1] = 2.0f / height;
		m_mat[2][2] = 1.0f / (far_plane - near_plane);
		m_mat[3][2] = -(near_plane / (far_plane - near_plane));
	}

public:
	float m_mat[4][4] = {};
};

#endif