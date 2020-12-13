# app.py - Stand alone predict module for dockerizing.


import nltk
import pandas as pd
import sklearn

nltk.download('stopwords')

FLASK_RUN_PORT = os.environ['FLASK_RUN_PORT']

DOMAIN = 'hackles'
DOMAINPATH = 'models/' + DOMAIN + '/'


app = Flask(__name__)

@app.route('/')
def index():
    return "DifferAnce Engine"

@app.route('/predict', methods = ['GET', 'POST'])
def predict():
    """ Expects a blob and a domain key to predict against. """
    #predict_req = request.form.to_dict()
    #blob = predict_req['text']
    #resp = prediction(blob)
    resp = prediction(request.form['text'])
    return Response(resp, mimetype='text/xml')

def load_model():
    model_path = DOMAINPATH + DOMAIN + '.pkl'
    #model_path = domain.pkl
    with open(model_path, 'rb') as file:
        model = pickle.load(file)

    return model

def prediction(blob):
    predict_frame = pd.DataFrame({'raw':[blob]})
    model = load_model()
    answer = model.predict(predict_frame)
    return answer

if __name__ == '__main__':
        app.run(host='0.0.0.0', port=FLASK_RUN_PORT, debug=True)
