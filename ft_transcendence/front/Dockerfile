FROM node:18.16.0

WORKDIR /app

COPY package.json ./

WORKDIR /app

RUN npm install

COPY . .

CMD [ "npm", "run", "dev" ]
