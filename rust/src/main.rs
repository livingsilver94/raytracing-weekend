mod color;
mod ray;
mod vec3;

use color::Color;
use ray::Ray;
use vec3::Vec3;

fn sky_color(ray: &Ray) -> Color {
	let t = 0.5 * (ray.dir.unit().y + 1.0);
	Color::new(1.0, 1.0, 1.0) * (1.0 - t) + Color::new(0.5, 0.7, 1.0) * t
}

fn main() {
	const ASPECT_RATIO: f64 = 16.0 / 9.0;
	const WIDTH: u32 = 400;
	const HEIGHT: u32 = WIDTH / ASPECT_RATIO as u32;

	const VIEWPORT_HEIGHT: f64 = 2.0;
	const VIEWPORT_WIDTH: f64 = VIEWPORT_HEIGHT * ASPECT_RATIO;
	const FOCAL_LENGTH: f64 = 1.0;

	let horizontal = Vec3 {
		x: VIEWPORT_WIDTH,
		y: 0.0,
		z: 0.0,
	};
	let vertical = Vec3 {
		x: 0.0,
		y: VIEWPORT_HEIGHT,
		z: 0.0,
	};
	let lower_left_corner = Vec3::origin()
		- horizontal / 2.0
		- vertical / 2.0
		- Vec3 {
			x: 0.0,
			y: 0.0,
			z: FOCAL_LENGTH,
		};

	println!("P3");
	println!("{} {}", WIDTH, HEIGHT);
	println!("255");

	for j in (0..HEIGHT).rev() {
		eprintln!("\rScanlines remaining: {}", j);
		for i in 0..WIDTH {
			let u = i as f64 / (WIDTH - 1) as f64;
			let v = j as f64 / (HEIGHT - 1) as f64;
			let ray = Ray {
				orig: Vec3::origin(),
				dir: lower_left_corner + horizontal * u + vertical * v,
			};
			let color = sky_color(&ray).rgb();
			println!("{} {} {}", color[0], color[1], color[2]);
		}
	}
}
