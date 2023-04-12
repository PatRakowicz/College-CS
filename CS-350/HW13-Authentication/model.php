<?php

class UserModel {
    private $db;

    function __construct() {
        $dsn = 'mysql:host=localhost; dbname=cs_350';
        $username = 'student';
        $password = 'CS350';

        try {
            $this->db = new PDO($dsn, $username, $password);
        } catch (PDOException $e) {
            exit('connection Failed: ' . $e->getMessage());
        }
    }

    function getAllUsers() {
        $data = $this->db->prepare('SELECT * FROM users');
        $data->execute();
        return $data->fetchAll(PDO::FETCH_ASSOC);
    }

    function getUserByUsername($username) {
        $data = $this->db->prepare('SELECT * FROM users WHERE username = :username');
        $data->bindValue(':username', $username);
        $data->execute();
        return $data->fetch(PDO::FETCH_ASSOC);
    }

    function createUser($username, $password) {
        $hashedPass = password_hash($password, PASSWORD_DEFAULT);
        $data = $this->db->prepare('INSERT INTO users (username, password) VALUES (:username, :password)');
        $data->bindValue(':username', $username);
        $data->bindValue(':password', $hashedPass);
        return $data->execute();
    }
}