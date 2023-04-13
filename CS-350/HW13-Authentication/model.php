<?php

class Model
{
    private $db;

    public function __construct()
    {
        // Connect to MySQL database using PDO
        $dsn = 'mysql:host=localhost;dbname=cs_350';
        $db_username = 'student';
        $db_password = 'CS350';

        try {
            $this->db = new PDO($dsn, $db_username, $db_password);
        } catch (PDOException $e) {
            echo "Connection failed: " . $e->getMessage();
            exit();
        }
//        $this->db = new PDO("mysql:host=$host;dbname=$dbname;charset=utf8", $username, $password);
//        $this->db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    }

    // Get all users from the database
    public function getAllUsers()
    {
        $stmt = $this->db->query("SELECT * FROM users");
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    public function createUser($username, $password)
    {
        $stmt = $this->db->prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
        $stmt->execute(array(':username' => $username, ':password' => password_hash($password, PASSWORD_DEFAULT)));
        return $stmt->rowCount() > 0;
    }

    public function getUserByUsername($username)
    {
        $stmt = $this->db->prepare("SELECT * FROM users WHERE username=:username");
        $stmt->execute(array(':username' => $username));
        return $stmt->fetch(PDO::FETCH_ASSOC);
    }

    public function isLoggedIn()
    {
        session_start();
        return isset($_SESSION['user']);
    }

    public function loginUser($username, $password)
    {
        $user = $this->getUserByUsername($username);
        if ($user && password_verify($password, $user['password'])) {
            session_start();
            $_SESSION['user'] = $user;
            return true;
        }
        return false;
    }

    public function logoutUser()
    {
        session_start();
        unset($_SESSION['user']);
        session_destroy();
    }

    public function getSecret()
    {
        if ($this->isLoggedIn()) {
            $username = $_SESSION['username'];
            $sql = "SELECT password FROM users WHERE username = :username";
            $stmt = $this->db->prepare($sql);
            $stmt->bindParam(":username", $username);
            $stmt->execute();
            $result = $stmt->fetch(PDO::FETCH_ASSOC);
            $password = $result['password'];
            return "Your password hash is: $password";
        }
        return false;
    }

    public function getUsers()
    {
        $stmt = $this->db->prepare('SELECT * FROM users');
        $stmt->execute();

        return $stmt->fetchAll();
    }
}
