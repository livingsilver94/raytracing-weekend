use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Neg, Sub, SubAssign};

#[derive(Clone, Copy)]
pub struct Vec3 {
	pub x: f64,
	pub y: f64,
	pub z: f64,
}

impl Vec3 {
	pub fn origin() -> Self {
		Self { x: 0.0, y: 0.0, z: 0.0 }
	}
	pub fn x() -> Self {
		Self { x: 1.0, ..Self::origin() }
	}
	pub fn y() -> Self {
		Self { y: 1.0, ..Self::origin() }
	}
	pub fn z() -> Self {
		Self { z: 1.0, ..Self::origin() }
	}
	pub fn dot(&self, other: &Self) -> f64 {
		self.x * other.x + self.y * other.y + self.z * other.z
	}
	pub fn cross(&self, other: &Self) -> Self {
		Self {
			x: self.y * other.z - self.x * other.y,
			y: self.z * other.x - self.x * other.z,
			z: self.x * other.y - self.y * other.x,
		}
	}
	pub fn len(&self) -> f64 {
		self.len_squared().sqrt()
	}
	pub fn len_squared(&self) -> f64 {
		self.x * self.x + self.y * self.y + self.z * self.z
	}
	pub fn unit(&self) -> Self {
		*self / self.len()
	}
}

impl Neg for Vec3 {
	type Output = Self;
	fn neg(self) -> Self::Output {
		Self { x: -self.x, y: -self.y, z: -self.z }
	}
}

impl Add for Vec3 {
	type Output = Self;
	fn add(self, other: Self) -> Self::Output {
		Self { x: self.x + other.x, y: self.y + other.y, z: self.z + other.z }
	}
}

impl Sub for Vec3 {
	type Output = Self;
	fn sub(self, other: Self) -> Self::Output {
		Self { x: self.x - other.x, y: self.y - other.y, z: self.z - other.z }
	}
}

impl Mul for Vec3 {
	type Output = Self;
	fn mul(self, other: Self) -> Self::Output {
		Self { x: self.x * other.x, y: self.y * other.y, z: self.z * other.z }
	}
}

impl Mul<f64> for Vec3 {
	type Output = Self;
	fn mul(self, f: f64) -> Self::Output {
		Self { x: self.x * f, y: self.y * f, z: self.z * f }
	}
}

impl Div for Vec3 {
	type Output = Self;
	fn div(self, other: Self) -> Self::Output {
		Self { x: self.x / other.x, y: self.y / other.y, z: self.z / other.z }
	}
}

impl Div<f64> for Vec3 {
	type Output = Self;
	fn div(self, f: f64) -> Self::Output {
		Self { x: self.x / f, y: self.y / f, z: self.z / f }
	}
}

impl AddAssign for Vec3 {
	fn add_assign(&mut self, other: Self) {
		self.x += other.x;
		self.y += other.y;
		self.z += other.z;
	}
}

impl SubAssign for Vec3 {
	fn sub_assign(&mut self, other: Self) {
		self.x -= other.x;
		self.y -= other.y;
		self.z -= other.z;
	}
}

impl MulAssign for Vec3 {
	fn mul_assign(&mut self, other: Self) {
		self.x *= other.x;
		self.y *= other.y;
		self.z *= other.z;
	}
}

impl DivAssign for Vec3 {
	fn div_assign(&mut self, other: Self) {
		self.x /= other.x;
		self.y /= other.y;
		self.z /= other.z;
	}
}
