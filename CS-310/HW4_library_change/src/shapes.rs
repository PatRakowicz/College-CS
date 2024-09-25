use std::f64::consts::PI;

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