use Lab5::user_management::profiles::Profile;

#[derive(Debug, Clone)]
pub enum Role {
    Admin,
    Editor,
    Viewer,
}

pub struct UserRole {
    pub profile: Profile,
    pub role: Role,
}