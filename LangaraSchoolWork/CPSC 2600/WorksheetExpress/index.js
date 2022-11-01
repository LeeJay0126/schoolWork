const express = require("express");
const members = require("./Members");
const logger = require("./Middleware/loggers");

const PORT = 5000;
const app = express();



app.use(logger);
app.get('/api/members', (req,res) => res.json(members));

app.listen(PORT, () => console.log(`Server started on port ${PORT}`));