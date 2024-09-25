struct Triangle {
    height: f64,
    base: f64,
    is_equilateral: bool,
    color: Color,
}

impl Triangle {
    fn new(height: f64, base: f64, color: Color) -> Self {
        Triangle {
            height,
            base,
            is_equilateral: height == base,
            color,
        }
    }

    fn new_equilateral(size: f64, color: Color) -> Self {
        Triangle {
            height: size,
            base: size,
            is_equilateral: true,
            color,
        }
    }

    fn area(&self) -> f64 {
        0.5 * self.base * self.height
    }

    fn print_info(&self) {
        println!(
            "Triangle: height={}, base={}, Area: {}, Color: {}, Is Equilateral: {}",
            self.height,
            self.base,
            self.area(),
            self.color.to_string(),
            self.is_equilateral
        );
    }
}