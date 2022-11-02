const express = require("express");
const logger = require("./Middleware/loggers");

const PORT = 5000;
const app = express();

app.use(logger);
app.use(express.json());
app.use(express.urlencoded({extended: false}));

app.use('/api/members', require('./Member'));

app.listen(PORT, () => console.log(`Server started on port ${PORT}`));