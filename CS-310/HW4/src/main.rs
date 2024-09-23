use std::f64::consts::PI;

// Enum for Color (already given in lab)
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

// Rectangle struct (already defined)
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

// Oval struct
struct Oval {
    short_axis: f64,
    long_axis: f64,
    is_circle: bool,
    color: Color,
}

impl Oval {
    fn new(short_axis: f64, long_axis: f64, color: Color) -> Self {
        Oval {
            short_axis,
            long_axis,
            is_circle: short_axis == long_axis,
            color,
        }
    }

    fn new_circle(radius: f64, color: Color) -> Self {
        Oval {
            short_axis: radius,
            long_axis: radius,
            is_circle: true,
            color,
        }
    }

    fn area(&self) -> f64 {
        PI * self.short_axis * self.long_axis
    }

    fn print_info(&self) {
        println!(
            "Oval: short_axis={}, long_axis={}, Area: {}, Color: {}, Is Circle: {}",
            self.short_axis,
            self.long_axis,
            self.area(),
            self.color.to_string(),
            self.is_circle
        );
    }
}

// Triangle struct
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

// Enum Shape
enum Shape {
    Rectangle { height: f64, width: f64 },
    Oval { short_axis: f64, long_axis: f64 },
    Triangle { base: f64, height: f64 },
}

impl Shape {
    fn area(&self) -> f64 {
        match self {
            Shape::Rectangle { height, width } => height * width,
            Shape::Oval { short_axis, long_axis } => PI * short_axis * long_axis,
            Shape::Triangle { base, height } => 0.5 * base * height,
        }
    }
}

fn main() {
    // Structs
    let oval = Oval::new(1.2, 2.5, Color::Red);
    let triangle = Triangle::new(5.0, 9.3, Color::Blue);
    let circle = Oval::new_circle(3.0, Color::Green);
    let equilateral_triangle = Triangle::new_equilateral(3.0, Color::RGB(255, 255, 0));

    oval.print_info();
    triangle.print_info();
    circle.print_info();
    equilateral_triangle.print_info();

    // Enum shapes
    let shape_rectangle = Shape::Rectangle { height: 3.5, width: 2.3 };
    let shape_oval = Shape::Oval { short_axis: 1.2, long_axis: 4.0 };
    let shape_triangle = Shape::Triangle { height: 5.3, base: 8.7 };

    println!("Shape Rectangle Area: {}", shape_rectangle.area());
    println!("Shape Oval Area: {}", shape_oval.area());
    println!("Shape Triangle Area: {}", shape_triangle.area());

    // "apple" hidden somewhere in the code ;)
    let _secret_word = "apple";
}