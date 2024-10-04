use crate::user_management::profiles::Profile;

#[derive(Debug, Clone)]
pub enum Role {
    Admin,
    Editor,
    Viewer,
}

pub struct UserRole<T> {
    pub profile: Profile<T>,
    pub role : Vec<Role>,
}

impl<T> UserRole<T> {
    pub fn new(profile: Profile<T>) -> Self{
        Self {
            profile,
            role: vec![Role::Viewer]
        }
    }

    pub fn display(&self) {
        println!("~~~User Role Information: ");
        println!("Profile Name: {}", self.profile.name);
        println!("Assigned Role: {:?}", self.role);
    }

    pub fn change_role(&mut self, new_role : Role) {
        self.role.push(new_role);
    }
}