use crate::user_management::profiles::Profile;

#[derive(Debug, Clone)]
pub enum Permission {
    Read(bool),
    Write(bool),
    Execute(bool),
}

pub struct UserPermissions {
    pub profile: Profile,
    pub permissions: [Permission; 3],
}