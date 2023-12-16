#include "libclean/mongoDB.hpp"

MongoDBConnector::MongoDBConnector() {
    
}

void MongoDBConnector::connect(std::string uri) {
    conn = mongocxx::client(mongocxx::uri(uri));
}

void MongoDBConnector::insertRobot(const Robot& robot) {
    // Convert the Robot object to BSON
    bsoncxx::builder::stream::document document{};
    document << "robot_id" << robot.getRobotID()
             << "robot_type" << robot.getRobotTypeString()
             << "robot_size" << robot.getRobotSizeString();

    // Insert the BSON object into the robots collection
    auto collection = conn["clean-squad-robot"]["robots_collection"];
    collection.insert_one(document.view());
}

void MongoDBConnector::insertRoom(const Room& room) {
    // Convert the Room object to BSON
    bsoncxx::builder::stream::document document{};
    document << "room_id" << room.getID()
             << "mop_time" << room.getMopTime()
             << "vacuum_time" << room.getVacuumTime()
             << "scrub_time" << room.getScrubTime();
             //<< "is_clean" << (room.getClean() ? "Clean" : "Not Clean");

    // Insert the BSON object into the rooms collection
    auto collection = conn["clean-squad-robot"]["rooms_collection"];
    collection.insert_one(document.view());

}

void MongoDBConnector::insertTask(const Task& task) {
  
    // Convert the Task object to BSON
    bsoncxx::builder::stream::document document{};
    document << "task_id" << task.getId()
             << "room_id" << task.getRoomID()
             << "mop_time" << task.getMopTime()
             << "vacuum_time" << task.getVacuumTime()
             << "scrub_time" << task.getScrubTime()
             << "is_completed" << (task.getIsCompleted() ? "Completed" : "Not Completed");


    // Insert the BSON object into the tasks collection
    auto collection = conn["clean-squad-robot"]["tasks_collection"];
    collection.insert_one(document.view());

}
