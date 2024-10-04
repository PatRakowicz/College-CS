use std::collections::HashMap;
use crate::user_management::profiles::Profile;

/*#[derive(Debug, Clone)]
pub enum Permission {
    Read(bool),
    Write(bool),
    Execute(bool),
}*/

pub struct UserPermission<T> {
    pub profile: Profile<T>,
    pub permissions: HashMap<String, bool>
}

impl<T> UserPermission<T> {
    pub fn new(profile: Profile<T>) -> Self {
        let mut permissions = HashMap::new();

        permissions.insert("read".to_string(), false);
        permissions.insert("write".to_string(), false);
        permissions.insert("execute".to_string(), false);

        Self { profile, permissions }
    }

    pub fn display(&self) {
        println!("~~~User Permissions for {}:", self.profile.name);
        for (permission, is_granted) in &self.permissions {
            println!("{}: {}", permission, if *is_granted { "True" } else { "False" });
        }
    }

    pub fn add_permissions(&mut self, permission: &String) {
        if let Some(p) = self.permissions.get_mut(permission) { *p = true; }
    }
    pub fn remove_permissions(&mut self, permission: &String) {
        if let Some(p) = self.permissions.get_mut(permission) { *p = false; }
    }
}