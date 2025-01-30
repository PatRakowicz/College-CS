
from pymongo.mongo_client import MongoClient
from pymongo.server_api import ServerApi

uri = "mongodb+srv://rako:sshrat@bigdata.8q6te.mongodb.net/?retryWrites=true&w=majority&appName=BigData"

client = MongoClient(uri, server_api=ServerApi('1'))

try:
	# connect to database
	db = client["sample_mflix"]
	
	# iterate over collections in database and print out their names
#	for coll in db.list_collection_names():
#       		print(coll)
	# access specific collection in database
	
	movies = db["movies"]
#	movies.insert_many([{"title": "Marriage Story"},{"title":"Toy Story 4"}])

	print("find all")	
	print(movies.count_documents({"year":{"$gt": 2015}}))

except Exception as e:
	print(e)
