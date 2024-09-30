use crate::user_management::profiles::Profile;

#[derive(Debug, Clone)]
pub enum Permission {
    Read(bool),
    Write(bool),
    Execute(bool),
}

pub struct UserPermission {
    pub profile: Profile,
    pub permissions: [bool; 3]
}

impl UserPermission {
    pub fn new (profile: Profile) -> Self {
        Self {
            profile,
            permissions: [false, false, false]
        }
    }

    pub fn display(&self) {
        println!("~~~User Permissions for {}:", self.profile.name);
        let permission_names = ["Read", "Write", "Execute"];
        for (i, perm) in self.permissions.iter().enumerate() {
            println!("{}: {}", permission_names[i], if *perm { "True" } else { "False" });
        }
    }

    pub fn add_permissions(&mut self, permission: usize) {
        if permission < self.permissions.len() {
            self.permissions[permission] = true
        }
    }
    pub fn remove_permissions(&mut self, permission: usize) {
        if permission < self.permissions.len() {
            self.permissions[permission] = false
        }
    }
}