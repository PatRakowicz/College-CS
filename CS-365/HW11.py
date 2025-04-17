import praw
from pyspark.ml.evaluation import RegressionEvaluator
from pyspark.ml.regression import RandomForestRegressor
from pyspark.sql import SparkSession
from pyspark.ml.feature import Tokenizer, HashingTF, IDF
import pandas as pd

# Note: I really tried to get this to work, the prev sparkTest done in class
# works just fine, this one keeps shitting the bed.
# So I attempted to fill out the rest to the best of my ability,
# Couldn't really test anything since I kept getting errors.

# Spark
spark = SparkSession.builder.appName("RedditPostApp").getOrCreate()

# Reddit client
reddit = praw.Reddit(
    client_id="",
    client_secret="",
    user_agent="reddit_query"
)

# Collect posts
subreddit = reddit.subreddit("CryptoMarkets")
posts = []

# limited to 100 for test | IF I COULD TEST BUT I KEEP GETTING ERRORS!!!
for post in subreddit.top(limit=100):
    posts.append((post.title, post.score))

# posts_pd = pd.DataFrame(posts)

# Create Spark DataFrame
columns = ["title", "score"]
df = spark.createDataFrame(posts, columns)

# Tokenize text
tokenizer = Tokenizer(inputCol="title", outputCol="words")
words_data = tokenizer.transform(df)

# HashingTF
hashing_tf = HashingTF(inputCol="words", outputCol="rawTitles", numFeatures=20)
tf_data = hashing_tf.transform(words_data)

# IDF
idf = IDF(inputCol="rawTitles", outputCol="titles")
idf_model = idf.fit(tf_data)
rescaled_data = idf_model.transform(tf_data)

# Select features and label
final_data = rescaled_data.select("titles", "score")
print("Show final data")
final_data.show()

# Train/test split
train_data, test_data = final_data.randomSplit([0.8, 0.2])

# Regression model [randon forest model]
rf = RandomForestRegressor(featuresCol="titles", labelCol="score")
model = rf.fit(train_data)

# Evaluate
predictions = model.transform(test_data)

evalModel = RegressionEvaluator(labelCol="score", predictionCol="prediction", metricName="rmse")
rmse = evalModel.evaluate(predictions)
print(f"RMSE: {rmse:.2f}")

spark.stop()