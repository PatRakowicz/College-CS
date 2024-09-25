use std::f64::consts::PI;
mod shapes;
mod triangle;
use rectangle;
mod oval;

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

fn main() {
    let oval = Oval::new(1.2, 2.5, Color::Red);
    let triangle = triangle::new(5.0, 9.3, Color::Blue);
    let circle = Oval::new_circle(3.0, Color::Green);
    let equilateral_triangle = triangle::new_equilateral(3.0, Color::RGB(255, 255, 0));
    let shape_rectangle = Shape::Rectangle { height: 3.5, width: 2.3 };
    let shape_oval = Shape::Oval { short_axis: 1.2, long_axis: 4.0 };
    let shape_triangle = Shape::Triangle { height: 5.3, base: 8.7 };

    oval.print_info();
    triangle.print_info();
    circle.print_info();
    equilateral_triangle.print_info();

    println!("\n ~~~~~~~~~~~~~~~~~~~~~~ \n");

    println!("Shape Rectangle Area: {}", shape_rectangle.area());
    println!("Shape Oval Area: {}", shape_oval.area());
    println!("Shape Triangle Area: {}", shape_triangle.area());
}