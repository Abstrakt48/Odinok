#ifndef __VECTOR__
#define __VECTOR__

#include <math.h>

//
// Vector2D
//
class Vector2D
{
public:
	Vector2D() {}
	Vector2D(float x, float y) :x(x), y(y) {}
	Vector2D(const  Vector2D& vector) :x(vector.x), y(vector.y) {}

	Vector2D operator *(float num) const
	{
		return Vector2D(x * num, y * num);
	}
	Vector2D operator /(float num) const
	{
		return Vector2D(x / num, y / num);
	}
	Vector2D operator +(const  Vector2D& vec) const
	{
		return Vector2D(x + vec.x, y + vec.y);
	}
	Vector2D operator -(const  Vector2D& vec) const
	{
		return Vector2D(x - vec.x, y - vec.y);
	}

	Vector2D operator =(const Vector2D& vec) const
	{
		return Vector2D(vec.x, vec.y);
	}
	Vector2D operator =(float num) const
	{
		return Vector2D(num, num);
	}

public:
	float x = 0.0f, y = 0.0f;
};

//
// Vector3D
//
class Vector3D
{
public:
	Vector3D() {}
	Vector3D(float x, float y, float z) :x(x), y(y), z(z) {}
	Vector3D(const  Vector3D& vector) :x(vector.x), y(vector.y), z(vector.z) {}

	static Vector3D Lerp(const  Vector3D& start, const  Vector3D& end, float delta)
	{
		Vector3D v;
		v.x = start.x * (1.0f - delta) + end.x * (delta);
		v.y = start.y * (1.0f - delta) + end.y * (delta);
		v.z = start.z * (1.0f - delta) + end.z * (delta);
		return v;
	}

	Vector3D operator *(float num) const
	{
		return Vector3D(x * num, y * num, z * num);
	}

	Vector3D operator /(float num) const
	{
		return Vector3D(x / num, y / num, z / num);
	}

	Vector3D operator +(const  Vector3D& vec) const
	{
		return Vector3D(x + vec.x, y + vec.y, z + vec.z);
	}

	Vector3D operator -(const  Vector3D& vec) const
	{
		return Vector3D(x - vec.x, y - vec.y, z - vec.z);
	}

	Vector3D operator =(const Vector3D& vec) const
	{
		return Vector3D(vec.x, vec.y, vec.z);
	}
	Vector3D operator =(float num) const
	{
		return Vector3D(num, num, num);
	}

	float Length() const
	{
		return (float)sqrt((x * x) + (y * y) + (z * z));
	}

	static Vector3D Normalize(const  Vector3D& vec)
	{
		Vector3D res;
		float len = (float)sqrt((float)(vec.x * vec.x) + (float)(vec.y * vec.y) + (float)(vec.z * vec.z));
		if (!len)
			return Vector3D();

		res.x = vec.x / len;
		res.y = vec.y / len;
		res.z = vec.z / len;

		return res;
	}

	static Vector3D Cross(const  Vector3D& v1, const  Vector3D& v2)
	{
		Vector3D res;
		res.x = (v1.y * v2.z) - (v1.z * v2.y);
		res.y = (v1.z * v2.x) - (v1.x * v2.z);
		res.z = (v1.x * v2.y) - (v1.y * v2.x);
		return res;
	}

public:
	float x = 0.0f, y = 0.0f, z = 0.0f;
};

extern Vector3D vec_origin;

//
// Vector4D
//
class Vector4D
{
public:
	Vector4D() {}
	Vector4D(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {}
	Vector4D(const  Vector4D& vector) :x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}
	Vector4D(const  Vector3D& vector) :x(vector.x), y(vector.y), z(vector.z), w(1.0) {}

	Vector4D operator =(const Vector4D& vec) const
	{
		return Vector4D(vec.x, vec.y, vec.z, vec.w);
	}
	Vector4D operator =(float num) const
	{
		return Vector4D(num, num, num, num);
	}

	void Cross(Vector4D& v1, Vector4D& v2, Vector4D& v3)
	{
		this->x = v1.y * (v2.z * v3.w - v3.z * v2.w) - v1.z * (v2.y * v3.w - v3.y * v2.w) + v1.w * (v2.y * v3.z - v2.z * v3.y);
		this->y = -(v1.x * (v2.z * v3.w - v3.z * v2.w) - v1.z * (v2.x * v3.w - v3.x * v2.w) + v1.w * (v2.x * v3.z - v3.x * v2.z));
		this->z = v1.x * (v2.y * v3.w - v3.y * v2.w) - v1.y * (v2.x * v3.w - v3.x * v2.w) + v1.w * (v2.x * v3.y - v3.x * v2.y);
		this->w = -(v1.x * (v2.y * v3.z - v3.y * v2.z) - v1.y * (v2.x * v3.z - v3.x * v2.z) + v1.z * (v2.x * v3.y - v3.x * v2.y));
	}

public:
	float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;
};

#endif