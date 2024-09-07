/*
Patrick Rakowicz
HW2
CS 310
*/

fn gymnastics_score(difficulty: f64, execution: f64, deductions: f64) -> f64 {
    difficulty + execution - deductions
}

fn breakdancing_score(musicality: f64, vocabulary: f64, technique: f64, execution: f64, originality: f64, deduction_code: &str) -> f64 {
    let mut total_score = (musicality + vocabulary + technique + execution + originality) / 5.0;


    // Originally wanted to do this, but found this and it works
    // https://doc.rust-lang.org/rust-by-example/flow_control/match/destructuring/destructure_tuple.html
    /*
    if deduction_code == "mild" {
        total_score *= 0.97;  // -3%
    } else if deduction_code == "moderate" {
        total_score *= 0.94;  // -6%
    } else if deduction_code == "severe" {
        total_score *= 0.90;  // -10%
    }
    */

    match deduction_code {
        "mild" => total_score *= 0.97,     // -3%
        "moderate" => total_score *= 0.94, // -6%
        "severe" => total_score *= 0.90,   // -10%
        _ => {}
    }

    total_score
}

fn skateboarding_score(runs: [f64; 5]) -> f64 {
    let mut sorted_runs = runs;
    sorted_runs.sort_by(|a, b| a.partial_cmp(b).unwrap());

    (sorted_runs[1] + sorted_runs[2] + sorted_runs[3]) / 3.0
}

fn main() {
    let res = gymnastics_score(7.2, 7.9, 0.0);
    println!("Gymnastics score: {:.12}", res);

    let res = breakdancing_score(80.0, 75.0, 68.0, 72.0, 84.0, "mild");
    println!("Breakdancing score: {:.12}", res);

    let res = skateboarding_score([80.0, 75.0, 90.0, 80.0, 78.0]);
    println!("Skateboarding score: {:.12}", res);
}
