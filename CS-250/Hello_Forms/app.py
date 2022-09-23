from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('hw05.html')

@app.route('/handle_post', methods=['POST'])
def handle_post():
    return render_template('response.html', data=request.form)


if __name__ == "__main__":
    app.run()
