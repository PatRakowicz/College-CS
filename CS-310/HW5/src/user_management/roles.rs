use crate::user_management::profiles::Profile;

#[derive(Debug, Clone)]
pub enum Role {
    Admin,
    Editor,
    Viewer,
}

pub struct UserRole {
    pub profile: Profile,
    pub role : String,
}

impl UserRole {
    pub fn new(profile: Profile, role: &str) -> Self{
        Self {
            profile,
            role: role.to_string()
        }
    }

    pub fn display(&self) {
        println!("~~~User Role Information: ");
        println!("Profile Name: {}", self.profile.name);
        println!("Assigned Role: {}", self.role);
    }
}