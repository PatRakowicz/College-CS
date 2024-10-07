use crate::user_management::company::Company;
use crate::user_management::roles::Role;
use crate::user_management::permissions::UserPermission;
use crate::user_management::profiles::Profile;
use crate::user_management::roles::UserRole;


mod user_management;


// Author: Patrick Rakowicz
fn main() {
    /// Create a new profile
    let profile = Profile::new("user123", "John Doe", "johndoe@gmail.com");
    profile.display();
    println!("");
    println!("~~~~~");

    /// Create and display roles
    let mut user_role = UserRole::new();
    user_role.add_role(Role::Admin);
    user_role.display();
    println!("");
    println!("~~~~~");

    /// Create and manage permissions
    let mut user_permissions = UserPermission::new();
    user_permissions.add_permission("read");
    user_permissions.check_permission("write");
    user_permissions.display();
    println!("");
    println!("~~~~~");

    /// Create a company and add profiles
    let mut company = Company::new("Engineering", profile);
    let new_profile = Profile::new("user124", "Jane Doe", "janedoe@gmail.com");
    company.add_profile("Engineering", new_profile);
    company.list_all_profiles();
}
