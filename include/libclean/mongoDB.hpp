#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <vector>
#include "Robot.hpp"
#include "Room.hpp"
#include "Task.hpp"

class MongoDBConnector {
public:
    MongoDBConnector();
    void insertRobot(const Robot& robot);
    void insertRoom(const Room& room);
    void insertTask(const Task& task);
    void connect(std::string uri); // URI to MongoDB instance
   

private:
    mongocxx::instance instance{}; 
    mongocxx::client conn{};      
};
