
from pymongo.mongo_client import MongoClient
from pymongo.server_api import ServerApi

from dotenv import load_dotenv
import os

load_dotenv()
database_uri = os.getenv('DATABASE_URL')

client = MongoClient(database_uri, server_api=ServerApi('1'))

try:
	client.admin.command('ping')
	print("Pinged deployment, Connected")	
except Exception as e:
	print(e)
