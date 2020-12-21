#include <iostream>

int
main()
{
	const auto image_width = 256;
	const auto image_height = 256;

	const auto max_color = 255;

	// Print PPM header.
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n" << max_color << "\n";

	for (auto y = 0; y < image_height; y++) {
		std::cerr << "Processing line " << y + 1 << " over " << image_height << "\n";
		for (auto x = 0; x < image_width; x++) {
			const auto r = static_cast<int>(static_cast<double>(x) / image_width * max_color);
			const auto g = static_cast<int>(static_cast<double>(y) / image_height * max_color);
			constexpr auto b = static_cast<int>(0.25 * max_color);

			std::cout << r << ' ' << g << ' ' << b << '\n';
		}
	}
}
