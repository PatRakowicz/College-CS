from sklearn.ensemble import RandomForestRegressor
from ucimlrepo import fetch_ucirepo
from sklearn.model_selection import train_test_split

taiwanese_prediction = fetch_ucirepo(id=572)
X = taiwanese_prediction.data.features
Y = taiwanese_prediction.data.targets

x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size=0.2, random_state=42)

print("shape of input - training set", x_train.shape)
print("shape of output - training set", y_train.shape)
print("shape of input - testing set", x_test.shape)
print("shape of output - testing set", y_test.shape)

model = RandomForestRegressor(n_estimators=100, random_state=42)
model = model.fit(x_train, y_train)
y_pred = model.predict(x_test)

print("Y Prediction",y_pred)

