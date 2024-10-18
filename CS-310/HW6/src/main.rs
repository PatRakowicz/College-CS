use crate::user_management::company::Company;
use crate::user_management::roles::Role;
use crate::user_management::permissions::UserPermission;
use crate::user_management::profiles::Profile;
use crate::user_management::roles::UserRole;


mod user_management;


// Author: Patrick Rakowicz
fn main() {
    // Create a new profile
    let profile = Profile::new("user123", "John Doe", "johndoe@gmail.com");
    profile.display();
    println!("");
    println!("~~~~~");

    // Create a company and add profiles to it
    let mut company = Company::new("Engineering", &profile);

    // Add a new profile to the 'Engineering' department
    let new_profile = Profile::new("user124", "Jane Doe", "janedoe@gmail.com");
    company.add_profile("Engineering", &new_profile);

    // List all profiles in the company
    company.list_all_profiles();

    // Adding task assignment
    println!("~~~~~");
    let employee_ids = vec!["user123".to_string(), "user124".to_string()];
    company.assign_task("Complete system design".to_string(), employee_ids); // Not sure what's wrong.
//     emplyoee_id | type missmatch, expected Vec[&str] but found Vec[String] | IDE changed to [String] -> [&str]

    company.display_EmployeeTask();
}
