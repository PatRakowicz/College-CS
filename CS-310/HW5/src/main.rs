use crate::user_management::permissions::UserPermission;
use crate::user_management::profiles::Profile;
use crate::user_management::roles::UserRole;

mod user_management;

// Author: Patrick Rakowicz
fn main() {
    let profile = Profile::new("john Dow", "johndoe@gmail.com");
    profile.display();
    println!(" ");

    let user_role = UserRole::new(profile);
    user_role.display();

    let mut user_permissions = UserPermission::new(user_role.profile);
    user_permissions.display();
    println!(" ");

    println!("~~~Modifying permissions~~~");
    user_permissions.add_permissions();
    user_permissions.add_permissions(1);
    user_permissions.display();
    println!(" ");

    println!("~~~Reverting Write permissions~~~");
    user_permissions.remove_permissions(1);
    user_permissions.display();
}
