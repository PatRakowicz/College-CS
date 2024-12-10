from flask import Flask, jsonify
from random import uniform
from datetime import datetime, timedelta

app = Flask(__name__)

# Start time for the simulated weather
simulated_time = datetime.utcnow()

# Function to generate random weather data
def generate_weather_data():
    return {
        "temperature": round(uniform(20.0, 35.0), 2),
        "humidity": round(uniform(40.0, 90.0), 2),
        "uvi": round(uniform(0.0, 11.0), 2),
        "wind_speed": round(uniform(0.0, 20.0), 2)
    }

# API Route
@app.route('/api/weather', methods=['GET'])
def get_weather():
    global simulated_time

    # Generate new weather data
    weather_data = generate_weather_data()

    # Assign the current simulated timestamp
    weather_data["timestamp"] = simulated_time.strftime("%Y-%m-%dT%H:%M:%SZ")

    # Print the generated data for debugging
    print(f"Generated Weather Data: {weather_data}")

    # Advance simulated time by 1 hour per API call
    simulated_time += timedelta(minutes=1)

    return jsonify(weather_data)

# Run the Flask API Server
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000, debug=True)
