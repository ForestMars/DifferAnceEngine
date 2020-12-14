import pickle
import pandas as pd

DOMAIN = 'hackles'
DOMAINPATH = 'models/' + DOMAIN + '/'


def load_model():
    print('loaded model')
    model_path = DOMAINPATH + DOMAIN + '.pkl'
    #model_path = domain.pkl
    with open(model_path, 'rb') as file:
        model = pickle.load(file)

    return model


def prediction(blob):
    print('prediction fired')
    predict_frame = pd.DataFrame({'raw':[blob]})
    model = load_model()
    answer = model.predict(predict_frame)

    return answer
