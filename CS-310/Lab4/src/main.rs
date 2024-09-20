enum Color {
    Red,
    Blue,
    Green,
    RGB(u8, u8, u8),
}

impl Color {
    fn to_string(&self) -> String {
        match self {
            Color::Red => String::from("Red"),
            Color::Blue => String::from("Blue"),
            Color::Green => String::from("Green"),
            Color::RGB(r, g, b) => format!("RGB({}, {}, {})", r, g, b),
        }
    }
}

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

fn main() {
    let rect = Rectangle::new(2.0, 4.5, Color::Red);
    let square = Rectangle::new_square(3.0, Color::RGB(120, 200, 80));

    println!("Rectangle area: {}", rect.area());
    println!("Square area: {}", square.area());

    println!("Rectangle color: {}", rect.color.to_string());
    println!("Square color: {}", square.color.to_string());

    rect.print_info();
    square.print_info();
}
