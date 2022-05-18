use crate::color::Color;

mod color;

fn main() {
	const WIDTH: u32 = 256;
	const HEIGHT: u32 = 256;

	println!("P3");
	println!("{} {}", WIDTH, HEIGHT);
	println!("255");

	for j in (0..HEIGHT).rev() {
		eprintln!("\rScanlines remaining: {}", j);
		for i in 0..WIDTH {
			let color = Color {
				r: i as f64 / (WIDTH - 1) as f64,
				g: j as f64 / (WIDTH - 1) as f64,
				b: 0.25,
			}
			.rgb();
			println!("{} {} {}", color[0], color[1], color[2]);
		}
	}
}
