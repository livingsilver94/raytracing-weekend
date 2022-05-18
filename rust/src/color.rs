use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Neg, Sub, SubAssign};

#[derive(Clone, Copy)]
pub struct Color {
	pub r: f64,
	pub g: f64,
	pub b: f64,
}

impl Color {
	pub fn new(r: f64, g: f64, b: f64) -> Self {
		Self { r, g, b }
	}
	pub fn rgb(&self) -> [u8; 3] {
		let max = u8::MAX as f64;
		[
			(self.r * max) as u8,
			(self.g * max) as u8,
			(self.b * max) as u8,
		]
	}
}

impl Neg for Color {
	type Output = Self;
	fn neg(self) -> Self::Output {
		Self {
			r: -self.r,
			g: -self.g,
			b: -self.b,
		}
	}
}

impl Add for Color {
	type Output = Self;
	fn add(self, other: Self) -> Self::Output {
		Self {
			r: self.r + other.r,
			g: self.g + other.g,
			b: self.b + other.b,
		}
	}
}

impl Sub for Color {
	type Output = Self;
	fn sub(self, other: Self) -> Self::Output {
		Self {
			r: self.r - other.r,
			g: self.g - other.g,
			b: self.b - other.b,
		}
	}
}

impl Mul for Color {
	type Output = Self;
	fn mul(self, other: Self) -> Self::Output {
		Self {
			r: self.r * other.r,
			g: self.g * other.g,
			b: self.b * other.b,
		}
	}
}

impl Mul<f64> for Color {
	type Output = Self;
	fn mul(self, f: f64) -> Self::Output {
		Self {
			r: self.r * f,
			g: self.g * f,
			b: self.b * f,
		}
	}
}

impl Div for Color {
	type Output = Self;
	fn div(self, other: Self) -> Self::Output {
		Self {
			r: self.r / other.r,
			g: self.g / other.g,
			b: self.b / other.b,
		}
	}
}

impl Div<f64> for Color {
	type Output = Self;
	fn div(self, f: f64) -> Self::Output {
		Self {
			r: self.r / f,
			g: self.g / f,
			b: self.b / f,
		}
	}
}

impl AddAssign for Color {
	fn add_assign(&mut self, other: Self) {
		self.r += other.r;
		self.g += other.g;
		self.b += other.b;
	}
}

impl SubAssign for Color {
	fn sub_assign(&mut self, other: Self) {
		self.r -= other.r;
		self.g -= other.g;
		self.b -= other.b;
	}
}

impl MulAssign for Color {
	fn mul_assign(&mut self, other: Self) {
		self.r *= other.r;
		self.g *= other.g;
		self.b *= other.b;
	}
}

impl DivAssign for Color {
	fn div_assign(&mut self, other: Self) {
		self.r /= other.r;
		self.g /= other.g;
		self.b /= other.b;
	}
}
