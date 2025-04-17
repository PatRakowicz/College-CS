import time

from sklearn.manifold import LocallyLinearEmbedding
from ucimlrepo import fetch_ucirepo

from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, precision_score, recall_score
from sklearn.decomposition import PCA

#Conclustion
# PCA and LLE made the model be trained faster and given the stats of high accuracy,
# they both dropped the ball and gave imbalance issues where the model would only be predicted on one value.
# The original model, given with such a low APR (accuracy, precision, recall) this was the only
# one to output a given value for the APR. They are low, yes, but they did show something from the given data.

# see results at the print below.

taiwanese_prediction = fetch_ucirepo(id=572)
X = taiwanese_prediction.data.features
Y = taiwanese_prediction.data.targets

X_pca = PCA(n_components=2).fit_transform(X)
X_lle = LocallyLinearEmbedding(n_components=2, random_state=42).fit_transform(X)

x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size=0.2, random_state=42)
x_train_pca, x_test_pca, y_train_pca, y_test_pca = train_test_split(X_pca, Y, test_size=0.2, random_state=42)
x_train_lle, x_test_lle, y_train_lle, y_test_lle = train_test_split(X_lle, Y, test_size=0.2, random_state=42)


print("Training input shape:", x_train.shape)
print("Testing input shape:", x_test.shape)

model = GaussianNB()
modelPCA = GaussianNB()
modelLLE = GaussianNB()

# Default trained timer
start_train = time.time()
model.fit(x_train, y_train)
end_train = time.time()
start_pred = time.time()
y_pred = model.predict(x_test)
end_pred = time.time()

# PCA trained timer
start_trainPCA = time.time()
modelPCA.fit(x_train_pca, y_train_pca)
end_trainPCA = time.time()
start_predPCA = time.time()
y_pred_pca = modelPCA.predict(x_test_pca)
end_predPCA = time.time()

# LLE-reduced data
start_trainLLE = time.time()
modelLLE.fit(x_train_lle, y_train_lle)
end_trainLLE = time.time()
start_predLLE = time.time()
y_pred_lle = modelLLE.predict(x_test_lle)
end_predLLE = time.time()

# Default data
accuracy = accuracy_score(y_test, y_pred)
precision = precision_score(y_test, y_pred)
recall = recall_score(y_test, y_pred)

#PCA data
accuracyPCA = accuracy_score(y_test_pca, y_pred_pca)
precisionPCA = precision_score(y_test_pca, y_pred_pca)
recallPCA = recall_score(y_test_pca, y_pred_pca)

#LLE Data
accuracyLLE = accuracy_score(y_test_lle, y_pred_lle)
precisionLLE = precision_score(y_test_lle, y_pred_lle)
recallLLE = recall_score(y_test_lle, y_pred_lle)

print("~~Gaussian Naive Bayes Results~~")
print("Training time: {:.4f} seconds".format(end_train - start_train))
print("Prediction time: {:.4f} seconds".format(end_pred - start_pred))
print("Accuracy: {:.4f}".format(accuracy))
print("Precision: {:.4f}".format(precision))
print("Recall: {:.4f}".format(recall))

# - Very low accuracy (6.67%)
# - Extremely high recall (96.08%)
# - Very poor precision (3.71%)
# Training time was the slowest out of all of them, but produced a viable output.
# the model predicted nearly everything as bankrupt, a lot of the time its mislabeling the data, and just a wrong model for this.

print("---------------------")

print("~~PCA Reduced Data + GaussianNB~~")
print("Training time: {:.4f} seconds".format(end_trainPCA - start_trainPCA))
print("Prediction time: {:.4f} seconds".format(end_predPCA - start_predPCA))
print("Accuracy: {:.4f}".format(accuracyPCA))
print("Precision: {:.4f}".format(precisionPCA))
print("Recall: {:.4f}".format(recallPCA))

# PCA reduced the data set to 2 dimensions, with an accuracy of 96%
# but precision and recall outputted to 0
# leading to most of the data being lost in PCA

print("---------------------")

print("~~LLE Reduced Data + GaussianNB~~")
print("Training time: {:.4f} seconds".format(end_trainLLE - start_trainLLE))
print("Prediction time: {:.4f} seconds".format(end_predLLE - start_predLLE))
print("Accuracy: {:.4f}".format(accuracyLLE))
print("Precision: {:.4f}".format(precisionLLE))
print("Recall: {:.4f}".format(recallLLE))

# LLE Reduced was good on the accuracy of 96% again, but again with the method above,
# Again with the zero precision and recall.
# this is classifying everything as not bankrupt.