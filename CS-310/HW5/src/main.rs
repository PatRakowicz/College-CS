mod permissions;
mod profile;
mod role;

use std::ptr::null;
use profile::Profile;
use role::UserRole;
use permissions::UserPermission;


fn main() {
    let profile = Profile::new("john Dow", "johndoe@gmail.com");
    profile.display();
    println!(" ");

    let user_role = UserRole::new(profile, "Admin");
    user_role.display();

    let mut user_permissions = UserPermission::new(user_role.profile);
    user_permissions.display();
    println!(" ");


    println!("~~~Modifying permissions~~~");
    user_permissions.add_permissions(0);
    user_permissions.add_permissions(1);
    user_permissions.display();
    println!(" ");

    println!("~~~Reverting Write permissions~~~");
    user_permissions.remove_permissions(1);
    user_permissions.display();
}
