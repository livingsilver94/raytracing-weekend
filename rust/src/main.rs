fn main() {
	const WIDTH: u32 = 256;
	const HEIGHT: u32 = 256;

	println!("P3");
	println!("{} {}", WIDTH, HEIGHT);
	println!("255");

	for j in (0..HEIGHT).rev() {
		eprintln!("\rScanlines remaining: {}", j);
		for i in 0..WIDTH {
			let r = i as f64 / (WIDTH - 1) as f64;
			let g = j as f64 / (WIDTH - 1) as f64;
			let b = 0.25;

			println!(
				"{} {} {}",
				(255.0 * r) as i32,
				(255.0 * g) as i32,
				(255.0 * b) as i32,
			);
		}
	}
}
