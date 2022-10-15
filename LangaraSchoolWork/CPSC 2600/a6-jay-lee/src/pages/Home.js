import React, { useEffect, useState } from 'react';
import Posts from '../components/Posts';
import axios from 'axios';
import Spinner from '../components/Spinner';

function Home() {
  const [appState, setAppState] = useState({
    loading: false,
    posts: null,
  });

  useEffect(() => {
    async function fetchData() {
      setAppState({ loading: true });
      const apiURL = "https://jsonplaceholder.typicode.com/todos";
      const arrayList = await axios.get(apiURL);
      setAppState({ loading: false, posts: arrayList.data.slice(0, 5) });
    }
    fetchData();
  }, [setAppState]);

  return (
    <div>
      {appState.loading ? <Spinner/> : <Posts isLoading={appState.loading} posts={appState.posts} />}
    </div>
  );

}
export default Home;
