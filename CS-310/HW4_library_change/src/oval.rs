use std::f64::consts::PI;
use crate::Color;

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