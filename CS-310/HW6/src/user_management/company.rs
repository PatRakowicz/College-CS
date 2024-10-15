use std::collections::HashMap;
use crate::user_management::profiles::Profile;
use std::fmt::Debug;
use std::cmp::PartialOrd;
use std::cmp::Ord;

/// Struct representing a company with depart and profiles
pub struct Company<T: Debug + PartialOrd + Ord> { depart: HashMap<String, Vec<Profile<T>>> }  // Maps department names to a list of profiles

impl<T: Debug + PartialOrd + Ord> Company<T> {
    /// Creates a new `Company` with an initial department and profile
    pub fn new(initial_department: &str, initial_profile: Profile<T>) -> Self {
        let mut depart = HashMap::new();
        depart.insert(initial_department.to_string(), vec![initial_profile]);
        Self { depart }
    }

    /// Adds a new profile to the specified department
    pub fn add_profile(&mut self, department: &str, profile: Profile<T>) {
        self.depart
            .entry(department.to_string())
            .or_insert_with(Vec::new)
            .push(profile);
    }

    /// Retrieves a reference to the profiles of the specified department
    pub fn get_department_profiles(&self, department: &str) -> Option<&Vec<Profile<T>>> {
        self.depart.get(department)
    }

    /// Lists all profiles in all depart
    pub fn list_all_profiles(&self) {
        for (department, profiles) in &self.depart {
            println!("Department: {}", department);
            for profile in profiles {
                profile.display();
            }
        }
    }
}