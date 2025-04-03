from pyspark.ml.feature import VectorAssembler
from pyspark.sql import SparkSession
import pyspark.sql.functions as f
from pyspark.ml.regression import LinearRegression

spark = SparkSession.builder.appName("test").getOrCreate()

df = spark.read.csv("movie_ratings_dataset.csv", header=True)

df = df.withColumn("MovieID", f.col("MovieID").cast("integer"))
df = df.withColumn("Rating", f.col("Rating").cast("integer"))
ds = df.groupBy("MovieID").agg(f.mean("Rating"), f.count("Rating"))
print(ds)

assembler = VectorAssembler(inputCols=["count(Rating)"], outputCol="features")
data_set = assembler.transform(ds)

train_data,test_data = data_set.randomSplit([0.8, 0.2])

LinearModel = LinearRegression(featuresCol="features", labelCol="avg(Rating)")
linearModel = LinearModel.fit(data_set)

test_stats = linearModel.evaluate(test_data)
print(f"RMSE: {test_stats.rootMeanSquaredError}")
spark.stop()