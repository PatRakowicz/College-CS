use crate::Color;

struct Rectangle {
    height: f64,
    width: f64,
    is_square: bool,
    color: Color,
}

impl Rectangle {
    fn new_square(size: f64, color: Color) -> Self {
        Rectangle {
            height: size,
            width: size,
            is_square: true,
            color,
        }
    }

    fn new(height: f64, width: f64, color: Color) -> Self {
        Rectangle {
            height,
            width,
            is_square: height == width,
            color,
        }
    }

    fn area(&self) -> f64 {
        self.height * self.width
    }

    fn print_info(&self) {
        println!(
            "Rectangle: {}x{}, Area: {}, Color: {}, Is Square: {}",
            self.height,
            self.width,
            self.area(),
            self.color.to_string(),
            self.is_square
        );
    }
}