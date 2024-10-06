use crate::user_management::profiles::Profile;

#[derive(Debug, Clone)]
pub enum Role {
    Admin,
    Editor,
    Viewer,
}

pub struct UserRole<T> {
    pub profile: Profile<T>,
    pub roles : Vec<Role>,
}

impl<T> UserRole<T> {
    pub fn new(profile: Profile<T>) -> Self{
        Self {
            profile,
            roles: vec![Role::Viewer]
        }
    }

    pub fn display(&self) {
        println!("~~~User Role Information: ");
        println!("Profile Name: {}", self.profile.name);
        println!("Assigned Role: {:?}", self.roles);
    }

    pub fn change_role(&mut self, new_role : Role) {
        self.roles.push(new_role);
    }
}