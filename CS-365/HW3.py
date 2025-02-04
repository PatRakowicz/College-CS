from pymongo.mongo_client import MongoClient
from pymongo.server_api import ServerApi
from dotenv import load_dotenv
import os

load_dotenv()
database_uri = os.getenv('DATABASE_URL')

client = MongoClient(database_uri, server_api=ServerApi('1'))


def problem_1(db):
    # P1.a
    collections = db.list_collection_names()
    print(collections)
    print("======")

    # P1.b
    for collection_name in collections:
        doc_count = db[collection_name].count_documents({})
        print(f"{collection_name}: {doc_count} documents")
    print("======")

    # P1.c
    for collection_name in collections:
        documents = db[collection_name].find_one()
        print(f"{collection_name} fields: {list(documents.keys())}")
    print("======")


def problem_2(db):
    # P2.a
    results = db.restaurants.find({"borough": "Manhattan"}, {"name": 1, "cuisine": 1, "_id": 0})
    for doc in results:
        print(doc)
    print("======")

    # P2.b
    count = db.restaurants.count_documents({"borough": "Queens", "cuisine": "Italian"})
    print(f"Italian restaurants in Queens: {count}")
    print("======")


def problem_3(db):
    # P3
    root_restaurant = {
        "name": "Root Awakening",
        "cuisine": "Vegetarian",
        "borough": "Bronx",
        "address": {
            "street": "asylum road",
            "zipcode": "10454"
        }}
    db.restaurants.insert_one(root_restaurant)
    print("Root Awakening - Added to DB")
    print("======")


def problem_4(db):
    # P4
    update_grade = {
        "$set": {
            "grades": [
                {"grade": "A", "score": 6},
                {"grade": "B", "score": 18}
            ]}}
    db.restaurants.update_one({"name": "Root Awakening"}, update_grade)
    print("Updated restaurant")
    print("======")


def problem_5(db):
    # P5.a
    db.restaurants.delete_many({"borough": "Staten Island", "grades.grade": "C"})
    print("Deleted restaurant")
    print("======")

    # P5.b
    db.restaurants.delete_one({"name": "Root Awakening"})
    print("Deleted restaurant - Root Awakening")
    print("======")


def main():
    try:
        db = client["sample_restaurants"]

        # problem_1(db)
        # problem_2(db)
        # problem_3(db)
        # problem_4(db)
        # problem_5(db)

    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
