#include "taskmanager.h"

TaskManager::TaskManager(const TaskManager& other) {
    users = other.users;
    loggedInUser = other.loggedInUser;
}

TaskManager::TaskManager(TaskManager&& other) noexcept {
    users = std::move(other.users);
    loggedInUser = other.loggedInUser;
    other.loggedInUser = nullptr;
}

TaskManager::~TaskManager() {
    for (size_t i = 0; i < users.size(); i++)
    {
        delete users[i];
    }
    
    users.clear();
    loggedInUser = nullptr;
}

void TaskManager::registerUser(const std::string& username, const std::string& password) {
    users.push_back(new User(username, password));

    std::cout << "User " << username << " has been registered." << std::endl;
}

bool TaskManager::login(const std::string& username, const std::string& password) {
    for (User* user : users) {
        if (user->getUsername() == username && user->getPassword() == password) {
            loggedInUser = user;
            std::cout << "User " << username << " has been logged in." << std::endl;
            return true;
        }
    }

    std::cout << "Invalid username or password." << std::endl;
    return false;
}

void TaskManager::logout() {
    loggedInUser = nullptr;
    std::cout << "User has been logged out." << std::endl;
}

void TaskManager::addTaskForUser(const Task& task) {
    loggedInUser->addTask(new Task(task));
}

void TaskManager::deleteTaskForUser(const std::string& title) {
    if (loggedInUser) {
        loggedInUser->removeTask(title);
    }
}

void TaskManager::editTaskForUser(const std::string& title, const Task& updatedTask) {
    if (loggedInUser) {
        loggedInUser->editTask(title, updatedTask);
    }
}


void TaskManager::removeTaskForUser(const std::string& title) {
    if (loggedInUser) {
        loggedInUser->removeTask(title);
    }
}

void TaskManager::displayTasksForUser() const {
    if (loggedInUser) {
        loggedInUser->listTasks();
    }
}